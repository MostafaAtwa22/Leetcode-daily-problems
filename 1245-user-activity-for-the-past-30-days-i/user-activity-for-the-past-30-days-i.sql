/* Write your T-SQL query statement below */
With Valid 
As (
    Select * 
    From Activity 
    Where activity_date Between '2019-06-28' And '2019-07-27'
)
Select 
    activity_date as day,
    Count (Distinct user_id) as active_users
From Valid
Group By activity_date
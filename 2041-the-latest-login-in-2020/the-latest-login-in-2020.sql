/* Write your T-SQL query statement below */
Select 
    user_id,
    max(time_stamp) as last_stamp
From
    Logins l
Where 
    year(time_stamp) = 2020
Group By 
    user_id
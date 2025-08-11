/* Write your T-SQL query statement below */
With CTE as (
    Select email, Min(id) as id
    From Person
    Group By email
)

Delete From Person
Where id NOT in (
    Select id 
    From CTE
)
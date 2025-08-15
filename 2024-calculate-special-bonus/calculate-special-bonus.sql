/* Write your T-SQL query statement below */
Select 
    employee_id,
    CASE
        When employee_id % 2 = 0 Or name like 'M%' Then 0
        Else salary
    End as bonus
From 
    Employees
Order By employee_id
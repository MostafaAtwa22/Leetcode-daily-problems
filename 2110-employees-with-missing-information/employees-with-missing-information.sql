/* Write your T-SQL query statement below */
Select 
    ISNULL(e.employee_id, s.employee_id) as employee_id
From    
    Employees e Full outer Join Salaries s 
    On e.employee_id = s.employee_id
Where
    name is NULL Or salary is null
Order By 
    employee_id
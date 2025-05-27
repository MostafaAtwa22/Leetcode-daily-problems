# Write your MySQL query statement below
Select emp.name As 'Employee'
From Employee emp Join Employee sup
On emp.managerId = sup.id
Where emp.salary > sup.salary
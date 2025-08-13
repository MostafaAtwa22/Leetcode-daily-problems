/* Write your T-SQL query statement below */
Select Distinct num as ConsecutiveNums
From Logs l
Where 
    id <= (select max(id) - 2 as id from Logs)
AND 
    num = (Select num From Logs Where id = l.id + 1)
AND 
    num = (Select num From Logs Where id = l.id + 2)
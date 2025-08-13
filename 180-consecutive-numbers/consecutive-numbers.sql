/* Write your T-SQL query statement below */
Select Distinct num as ConsecutiveNums
From (
    Select num,
        Lead(num) Over (ORder By Id) as prev,
        lag(num) Over (ORder By Id) as next
    From Logs
) as t
Where prev = next and prev = num
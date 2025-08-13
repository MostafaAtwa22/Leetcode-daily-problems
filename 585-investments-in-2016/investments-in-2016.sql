/* Write your T-SQL query statement below */
With CTE AS (
    Select *,
        Count(lat) Over (partition By lat, lon) As latt,
        Count(tiv_2015) Over (Partition By tiv_2015) as count
    From Insurance 
)
Select 
    Round(Sum (tiv_2016), 2) as tiv_2016
From CTE 
Where 
    latt = 1 And count > 1
# Write your MySQL query statement below
Select
s.user_id,
ROUND(
    IFNULL(
        COUNT(CASE WHEN c.action = 'confirmed' THEN 1 ELSE NULL END) * 1.0 
        / NULLIF(COUNT(c.action), 0), 
        0
    ), 
    2
) AS confirmation_rate

From Signups s Left Join Confirmations c
On s.user_id = c.user_id
Group By user_id
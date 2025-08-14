/* Write your T-SQL query statement below */
With CTE As (
    Select 
        u.id, ISNULL(Sum(distance), 0) as travelled_distance
    From users u LEFT Join rides r
    On u.id = r.user_id
    Group by u.id
)
Select 
    u.name,travelled_distance
From 
    CTE c JOIN Users u
    On c.id = u.id
Order By 
    travelled_distance DESC, u.name
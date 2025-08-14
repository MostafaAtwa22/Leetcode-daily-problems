/* Write your T-SQL query statement below */
Select 
    actor_id, director_id
From 
    ActorDirector
Group By 
    actor_id, director_id
Having 
    count(*) >= 3 
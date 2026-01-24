-- Write your PostgreSQL query statement below
Select tweet_id 
From Tweets 
Where length(content) > 15
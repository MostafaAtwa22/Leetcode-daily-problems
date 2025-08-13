/* Write your T-SQL query statement below */
With CTE As (
    Select Distinct sell_date, product
    from Activities
)
Select 
    sell_date, 
    count(*) as num_sold,
    STRING_AGG(product, ',') WITHIN GROUP (ORDER BY product) AS products
From CTE a
Group By sell_date
order By sell_date
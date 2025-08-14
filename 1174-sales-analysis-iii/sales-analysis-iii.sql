/* Write your T-SQL query statement below */
Select Distinct
    p.product_id, p.product_name
From 
    Product p Join Sales s
    On p.product_id = s.product_id
Group By  
    p.product_id, p.product_name
Having 
    min(sale_date) >= '2019-01-01' and max(sale_date) <= '2019-03-31'
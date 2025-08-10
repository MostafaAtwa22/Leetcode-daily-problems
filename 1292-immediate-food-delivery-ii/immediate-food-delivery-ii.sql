/* Write your T-SQL query statement below */
With CTE As(
    Select * From (
        Select 
            customer_id, 
            order_date,
            customer_pref_delivery_date,
            DENSE_RANK() Over (Partition By customer_id Order By order_date) As RN
        From Delivery 
    ) as NewTable
    Where RN = 1
)
Select 
    Round(
        Count(CASE WHEN order_date = customer_pref_delivery_date ThEN 1 ELSE NULL End) * 100.0
            /    
        (count(*) * 1.0) 
        ,2) as immediate_percentage 
From CTE
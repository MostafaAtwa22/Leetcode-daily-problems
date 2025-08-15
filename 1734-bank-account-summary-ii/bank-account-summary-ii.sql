/* Write your T-SQL query statement below */
With CTE As (
    Select u.account, u.name, sum(amount) as balance
    From Users u Join Transactions t 
    On u.account = t.account
    Group By u.account, u.name
    Having sum(amount) > 10000
)
Select name, balance From CTE
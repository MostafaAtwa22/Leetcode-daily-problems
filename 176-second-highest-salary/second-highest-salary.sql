SELECT
    ISNULL((
        SELECT TOP(1) Salary
        FROM (
            SELECT Salary,
                   DENSE_RANK() OVER (ORDER BY Salary DESC) AS RN
            FROM Employee
            WHERE Salary IS NOT NULL
        ) AS t
        WHERE RN = 2
    ), NULL) AS SecondHighestSalary;

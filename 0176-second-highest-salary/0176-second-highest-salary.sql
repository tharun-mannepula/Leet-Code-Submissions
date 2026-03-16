# Write your MySQL query statement below
select max(salary) as SecondHighestSalary
FROM Employee
WHERE salary < (select max(salary)
                 FROM Employee);
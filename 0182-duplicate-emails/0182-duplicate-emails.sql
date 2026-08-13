# Write your MySQL query statement below
select email
FROM person
Group by email
Having count(*)>1;

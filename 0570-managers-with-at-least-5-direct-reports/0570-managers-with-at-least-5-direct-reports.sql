# Write your MySQL query statement below
select e2.name
from Employee e1
join Employee e2
ON e1.managerId = e2.id
Group by e1.managerId
HAVING count(*) >= 5;
-- where 
-- id IN
-- (select managerId
-- from Employee
-- group by managerId
-- having count(*)>=5);
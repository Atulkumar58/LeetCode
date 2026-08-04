# Write your MySQL query statement below
SELECT p.email as Email
FROM Person p
group by p.email
having count(*)>1;
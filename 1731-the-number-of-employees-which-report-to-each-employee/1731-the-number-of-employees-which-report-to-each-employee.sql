# Write your MySQL query statement below
select 
e2.employee_id,
e2.name,
count(*) as reports_count,
round(AVG(e1.age)) as average_age
from Employees e1
join Employees e2
ON e1.reports_to = e2.employee_id
group by e1.reports_to
having e1.reports_to is not null
Order BY e2.employee_id;
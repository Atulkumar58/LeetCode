# Write your MySQL query statement below
select class
from Courses
Group by class
having count(distinct(student)) >4;
# Write your MySQL query statement below
select e.name as Employee from Employee as e left join Employee as e2
on e.managerId = e2.id
where e2.salary < e.salary;
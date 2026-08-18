# Write your MySQL query statement below
select 
activity_date as day,
count(Distinct(user_id)) as active_users
from Activity
group by activity_date
having DATEDIFF("2019-07-27", activity_date) < 30 and DATEDIFF("2019-07-27", activity_date)>=0;
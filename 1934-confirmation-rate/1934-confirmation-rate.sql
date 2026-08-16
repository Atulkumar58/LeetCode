# Write your MySQL query statement below
select s.user_id,
round(ifNULL(avg(c.action=1), 0),2) as confirmation_rate
from Signups s
left join Confirmations c
On s.user_id = c.user_id
group by s.user_id;
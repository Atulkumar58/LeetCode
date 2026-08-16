select
q.query_name,
round(avg(rating/position), 2) as quality,
round(q2.poor_query_percentage*100, 2) as poor_query_percentage
From Queries q
join (select query_name, sum(rating < 3)/count(*) as poor_query_percentage
from Queries
Group by query_name) q2
ON q.query_name = q2.query_name
group by query_name;
select
q.query_name,
round(avg(rating/position), 2) as quality,
round(sum(rating < 3)*100/count(*), 2) as poor_query_percentage
From Queries q
group by query_name;
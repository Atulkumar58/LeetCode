-- -- # Write your MySQL query statement below
select 
round(sum(p2 is not null)/COUNT(*), 2)
as fraction
from 
    (select
    a.player_id,
    a2.player_id as p2
    from Activity a
    left join Activity a2
    ON a.player_id = a2.player_id 
    and a2.event_date = DATE_ADD(a.event_date, INTERVAL 1 DAY)
    where (a.player_id,a.event_date) IN (
        select 
        player_id,
        min(event_date) as event_date
        from Activity
        Group by player_id
    )
    Group by a.player_id) 
    as s;
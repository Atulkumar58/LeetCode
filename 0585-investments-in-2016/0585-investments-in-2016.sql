# Write your MySQL query statement below
select round(sum(tiv_2016), 2) as tiv_2016
from Insurance
where tiv_2015 IN (select tiv_2015
from Insurance
Group by tiv_2015
having count(*)>1)

AND

pid in (
    select pid
    from Insurance
    Group by lat, lon
    having count(*)=1
);
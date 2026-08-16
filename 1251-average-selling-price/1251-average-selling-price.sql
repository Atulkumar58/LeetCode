# Write your MySQL query statement below
select p.product_id, 
Round(IFNULL(sum(units*price)/sum(units), 0), 2) as average_price
from Prices p
left join UnitsSold u
On p.product_id = u.product_id
-- group by p.product_id
where (datediff(u.purchase_date, start_date)>=0
and datediff(end_date, purchase_date) >= 0) 
OR u.product_id IS NULL
group by p.product_id;
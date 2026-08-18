select 
round(avg(order_date = customer_pref_delivery_date) *100, 2)
as immediate_percentage
From Delivery
where
(customer_id, order_date)
IN
(select  
customer_id,
min(order_date) as order_date
from Delivery 
group by customer_id)

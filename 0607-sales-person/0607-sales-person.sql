select name
from SalesPerson
where sales_id
NOT IN (select  Orders.sales_id
from Orders 
left join SalesPerson ON Orders.sales_id=SalesPerson.sales_id
left join Company ON Orders.com_id = Company.com_id
where Company.name = "RED")
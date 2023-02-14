select b.category, sum(s.sales) as total_sales
from book b
join book_sales s
on b.book_id = s.book_id
where year(s.sales_date) = 2022 and month(s.sales_date) = 1
group by b.category
order by b.category asc;
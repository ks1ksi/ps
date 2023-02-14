select a.author_id, a.author_name, b.category, sum(s.total * b.price) as total_sales
from book b
join author a on a.author_id = b.author_id
join (
    select book_id, sum(sales) as total
    from book_sales
    where year(sales_date) = 2022 and month(sales_date) = 1
    group by book_id
) s on s.book_id = b.book_id
group by 2, 3
order by 1 asc, 3 desc;
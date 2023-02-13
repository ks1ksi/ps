set @today = cast('2022-10-16' as date);

select car_id, (
    if (max(end_date) >= @today, '대여중', '대여 가능')
) as availability
from car_rental_company_rental_history
where start_date <= @today
group by car_id
order by car_id desc;
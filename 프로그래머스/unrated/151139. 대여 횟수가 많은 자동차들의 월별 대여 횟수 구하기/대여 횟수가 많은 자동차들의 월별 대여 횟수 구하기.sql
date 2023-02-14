select month(start_date) as month, car_id, count(*) as records
from car_rental_company_rental_history
where car_id in (
    select distinct car_id
    from car_rental_company_rental_history
    where start_date between date('2022-08-01 00:00:00') and date('2022-10-31 23:59:59')
    group by car_id
    having count(*) >= 5
)
and start_date between date('2022-08-01 00:00:00') and date('2022-10-31 23:59:59')
group by month, car_id
having records > 0
order by month asc, car_id desc
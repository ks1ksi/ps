select m.member_name, r.review_text, date_format(r.review_date, '%Y-%m-%d') as review_date
from rest_review r
join (
    select member_id, count(*) as cnt
    from rest_review r
    group by member_id
    order by cnt desc
    limit 1
) t on t.member_id = r.member_id
join member_profile m
on m.member_id = r.member_id
order by review_date, review_text
select a.apnt_no, p.pt_name, a.pt_no, a.mcdp_cd, d.dr_name, a.apnt_ymd
from appointment a
join patient p on p.pt_no = a.pt_no
join doctor d on d.dr_id = a.mddr_id
where a.mcdp_cd = 'CS' and a.apnt_cncl_yn = 'N' and a.apnt_ymd like '2022-04-13 %'
order by 6
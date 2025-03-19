-- 코드를 입력하세요
SELECT MCDP_CD as 진료과코드, COUNT(MCDP_CD) as 5월예약건수 
from APPOINTMENT 
where MONTH(APNT_YMD) = 5
group by MCDP_CD order by COUNT(MCDP_CD) , MCDP_CD;
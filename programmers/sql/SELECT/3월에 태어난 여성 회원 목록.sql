-- 3월 한정 조건을 이렇게 걸어도 되는 것인지 잘 모르겠음..
SELECT MEMBER_ID, MEMBER_NAME, GENDER, DATE_FORMAT(DATE_OF_BIRTH, '%Y-%m-%d') AS DATE_OF_BIRTH from MEMBER_PROFILE
where GENDER = 'W' and DATE_OF_BIRTH like '%-03-%' and TLNO is not NULL
order by MEMBER_ID;

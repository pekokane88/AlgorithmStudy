-- count 는 null 은 자연스럽게 예외시킨다. 따라서 where 문에 not null 구문은 추가하지 않았다.
SELECT count(AGE) as USERS from USER_INFO
where JOINED like '2021%' and AGE between 20 and 29;

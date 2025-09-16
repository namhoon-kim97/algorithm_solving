-- 코드를 입력하세요
SELECT
    b.TITLE,
    b.BOARD_ID,
    r.REPLY_ID,
    r.WRITER_ID,
    r.CONTENTS,
    DATE_FORMAT(r.CREATED_DATE, '%Y-%m-%d') as CREATED_DATE
FROM USED_GOODS_BOARD AS b
JOIN USED_GOODS_REPLY AS r
  ON r.BOARD_ID = b.BOARD_ID
where DATE_FORMAT(b.CREATED_DATE, '%Y-%m') = '2022-10'
order by r.created_date asc , b.title asc;
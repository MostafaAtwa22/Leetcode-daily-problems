/* Write your T-SQL query statement below */
With CTE As (
    Select 
        b.book_id, count(*) as current_borrowers
    From library_books b Join borrowing_records r 
    ON b.book_id = r.book_id
    where r.return_date is NULL 
    Group By b.book_id
    Having count(r.book_id) = (
        Select total_copies From library_books Where book_id = b.book_id
    )
)
Select 
    l.book_id, l.title, l.author, l.genre, l.publication_year, e.current_borrowers
From library_books l Join CTE e
on e.book_id = l.book_id
Order By e.current_borrowers DESC, l.title
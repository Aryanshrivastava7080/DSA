# Write your MySQL query statement below
select Person.lastName,
person.firstName,
Address.city,
Address.state
from Person
Left join Address
on Person.personId=Address.PersonId;

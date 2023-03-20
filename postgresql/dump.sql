-- Inserimento di alcuni record nella tabella "drink"
INSERT INTO drink (nome, categoria, descrizione, prezzo, immagine)
VALUES
('Mojito', 'Alcolici', 'Un cocktail a base di rum, lime, zucchero di canna, soda e foglie di menta', 7.50, pg_read_binary_file('images/mojito.jpg')),
('Spritz', 'Alcolici', 'Un cocktail a base di prosecco, aperol e soda', 6.50, pg_read_binary_file('images/spritz.jpg')),
('Acqua', 'Analcolici', 'Acqua naturale o frizzante', 1.50, pg_read_binary_file('images/acqua.jpg')),
('Coca-Cola', 'Analcolici', 'Bevanda gassata al gusto di cola', 2.00, pg_read_binary_file('images/cocacola.jpg')),
('Frullato di frutta', 'Frullati', 'Frullato di fragole, banane e yogurt', 4.50, pg_read_binary_file('images/frullato.jpg'));

-- Inserimento di alcuni record nella tabella "utente"
INSERT INTO utente (nome, cognome, email, password)
VALUES
('Mario', 'Rossi', 'mario.rossi@example.com', 'mario123'),
('Luca', 'Bianchi', 'luca.bianchi@example.com', 'luca123'),
('Anna', 'Verdi', 'anna.verdi@example.com', 'anna123');

-- Inserimento di alcuni record nella tabella "ordine"
INSERT INTO ordine (utente_id, data_ordine)
VALUES
(1, '2022-03-15 14:30:00'),
(1, '2022-03-17 16:45:00'),
(2, '2022-03-18 10:15:00'),
(3, '2022-03-19 12:00:00'),
(3, '2022-03-20 19:30:00');

-- Inserimento di alcuni record nella tabella "drink_ordine"
INSERT INTO drink_ordine (drink_id, ordine_id, quantita, prezzo)
VALUES
(1, 1, 1, 7.50),
(2, 1, 2, 6.50),
(3, 2, 1, 1.50),
(4, 2, 1, 2.00),
(5, 3, 1, 4.50),
(1, 3, 1, 7.50),
(2, 4, 1, 6.50),
(5, 4, 2, 9.00),
(1, 5, 2, 15.00),
(3, 5, 1, 1.50);
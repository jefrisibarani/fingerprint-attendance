-- Table: fp_public_holiday

-- DROP TABLE fp_public_holiday;

CREATE TABLE fp_public_holiday
(
  id smallint,
  date date NOT NULL,
  description character varying(30),
  CONSTRAINT fp_attendance_holiday_pkey PRIMARY KEY (date)
)
WITH (
  OIDS=FALSE
);
ALTER TABLE fp_public_holiday
  OWNER TO absensi;
GRANT ALL ON TABLE fp_public_holiday TO sclops;

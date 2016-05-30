-- Table: fp_last_recorded_time

-- DROP TABLE fp_last_recorded_time;

CREATE TABLE fp_last_recorded_time
(
  last_time character varying(50),
  id integer NOT NULL,
  CONSTRAINT fp_last_recorded_time_pkey PRIMARY KEY (id)
)
WITH (
  OIDS=FALSE
);
ALTER TABLE fp_last_recorded_time
  OWNER TO absensi;
GRANT ALL ON TABLE fp_last_recorded_time TO sclops;

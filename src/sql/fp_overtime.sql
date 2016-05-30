-- Table: fp_overtime

-- DROP TABLE fp_overtime;

CREATE TABLE fp_overtime
(
  id integer NOT NULL,
  mode character varying(15),
  CONSTRAINT fp_ovetime_pkey PRIMARY KEY (id),
  CONSTRAINT fp_ovetime_mode_key UNIQUE (mode)
)
WITH (
  OIDS=FALSE
);
ALTER TABLE fp_overtime
  OWNER TO absensi;

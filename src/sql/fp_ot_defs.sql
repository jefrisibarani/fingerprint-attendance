-- Table: fp_ot_defs

-- DROP TABLE fp_ot_defs;

CREATE TABLE fp_ot_defs
(
  id smallint NOT NULL,
  hours numeric(3,1) NOT NULL,
  mon numeric(3,1) NOT NULL,
  tue numeric(3,1) NOT NULL,
  wed numeric(3,1) NOT NULL,
  thu numeric(3,1) NOT NULL,
  fri numeric(3,1) NOT NULL,
  sat numeric(3,1) NOT NULL,
  sun numeric(3,1) NOT NULL,
  ph numeric(3,1) NOT NULL,
  ph_sat numeric(3,1) NOT NULL,
  CONSTRAINT fp_ot_defs_pkey PRIMARY KEY (id)
)
WITH (
  OIDS=FALSE
);
ALTER TABLE fp_ot_defs
  OWNER TO absensi;

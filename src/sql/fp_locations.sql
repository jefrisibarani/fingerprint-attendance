-- Table: fp_locations

-- DROP TABLE fp_locations;

CREATE TABLE fp_locations
(
  id integer NOT NULL,
  code text NOT NULL,
  CONSTRAINT fp_locations_pkey PRIMARY KEY (id)
)
WITH (
  OIDS=FALSE
);
ALTER TABLE fp_locations
  OWNER TO absensi;

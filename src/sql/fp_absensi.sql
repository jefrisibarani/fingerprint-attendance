-- Table: fp_absensi

-- DROP TABLE fp_absensi;

CREATE TABLE fp_absensi
(
  id serial NOT NULL ,
  kode_karyawan character varying(30) NOT NULL,
  nama_karyawan character varying(30), -- tidak harus ada, hanya untuk mempermudah pembacaan tabel
  jam_absen character varying(256) NOT NULL, -- waktu absensi
  tipe_absen character varying(6) NOT NULL, -- MASUK atau PULANG
  kode_lokasi character varying(255), -- Lokasi pelaksanaan absensi....
  device_sn character varying(40), -- serial number fingerprint reader device.
  jumlah_coba character(1),
  last_operator_name text,
  last_modified timestamp without time zone DEFAULT now(),
  CONSTRAINT fp_absensi_primarykey PRIMARY KEY (id)
)
WITH (
  OIDS=FALSE
);
ALTER TABLE fp_absensi
  OWNER TO absensi;
GRANT ALL ON TABLE fp_absensi TO sclops;
COMMENT ON COLUMN fp_absensi.nama_karyawan IS 'tidak harus ada, hanya untuk mempermudah pembacaan tabel';
COMMENT ON COLUMN fp_absensi.jam_absen IS 'waktu absensi';
COMMENT ON COLUMN fp_absensi.tipe_absen IS 'MASUK atau PULANG';
COMMENT ON COLUMN fp_absensi.kode_lokasi IS 'Lokasi pelaksanaan absensi.
tidak harus ada.
';
COMMENT ON COLUMN fp_absensi.device_sn IS 'serial number fingerprint reader device.
';


-- Trigger: insert_last_modified on fp_absensi

-- DROP TRIGGER insert_last_modified ON fp_absensi;

CREATE TRIGGER insert_last_modified
  BEFORE UPDATE
  ON fp_absensi
  FOR EACH ROW
  EXECUTE PROCEDURE moddatetime('last_modified');

-- Trigger: insert_operator_name on fp_absensi

-- DROP TRIGGER insert_operator_name ON fp_absensi;

CREATE TRIGGER insert_operator_name
  BEFORE INSERT OR UPDATE
  ON fp_absensi
  FOR EACH ROW
  EXECUTE PROCEDURE insert_username('last_operator_name');


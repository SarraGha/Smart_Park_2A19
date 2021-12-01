--------------------------------------------------------
--  Fichier cr�� - lundi-novembre-08-2021   
--------------------------------------------------------
DROP TABLE "SARRA"."ANIMAUX";
DROP TABLE "SARRA"."EMPLOYES";
DROP TABLE "SARRA"."FOURNIR";
DROP TABLE "SARRA"."MAGASINS";
DROP TABLE "SARRA"."PRENDRE_EN_CHARGE";
DROP TABLE "SARRA"."PRODUITS";
DROP TABLE "SARRA"."VISITES";
--------------------------------------------------------
--  DDL for Table ANIMAUX
--------------------------------------------------------

  CREATE TABLE "SARRA"."ANIMAUX" 
   (	"ID_ANIMAL" NUMBER, 
	"LIBELLE" VARCHAR2(256 BYTE), 
	"NUMERO_CAGE" NUMBER, 
	"NOURRITURE" VARCHAR2(256 BYTE), 
	"AGE" NUMBER, 
	"RECLAMATION" VARCHAR2(256 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table EMPLOYES
--------------------------------------------------------

  CREATE TABLE "SARRA"."EMPLOYES" 
   (	"ID_EMPLOYE" VARCHAR2(20 BYTE), 
	"NOM" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE), 
	"SALAIRE" FLOAT(126), 
	"RECLAMATION" VARCHAR2(20 BYTE), 
	"ID_EMPLOYE_FK1" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table FOURNIR
--------------------------------------------------------

  CREATE TABLE "SARRA"."FOURNIR" 
   (	"ID_PRODUIT_PK1" NUMBER, 
	"ID_ANIMAL_PK2" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table MAGASINS
--------------------------------------------------------

  CREATE TABLE "SARRA"."MAGASINS" 
   (	"ID_MAGASIN" VARCHAR2(20 BYTE), 
	"PRIX_LOCATION" FLOAT(126), 
	"ETAT" NUMBER, 
	"ID_LOCATAIRE" VARCHAR2(20 BYTE), 
	"LIBELLE" VARCHAR2(20 BYTE), 
	"ID_EMPLOYES_FK1" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table PRENDRE_EN_CHARGE
--------------------------------------------------------

  CREATE TABLE "SARRA"."PRENDRE_EN_CHARGE" 
   (	"ID_ANIMAL_PK1" NUMBER, 
	"ID_EMPLOYE_PK2" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table PRODUITS
--------------------------------------------------------

  CREATE TABLE "SARRA"."PRODUITS" 
   (	"ID_PRODUIT" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"LIBELLE" VARCHAR2(20 BYTE), 
	"NBRE_EXP" NUMBER, 
	"ID_FOURNISSEUR" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table VISITES
--------------------------------------------------------

  CREATE TABLE "SARRA"."VISITES" 
   (	"IDENTIFIANTTICKET" VARCHAR2(20 BYTE), 
	"PRIXTICKET" NUMBER, 
	"IDENTIFIANTVISITEUR" VARCHAR2(20 BYTE), 
	"NOMBREVISITES" NUMBER, 
	"DATEVISITE" VARCHAR2(20 BYTE), 
	"ABONNEMENT" VARCHAR2(20 BYTE), 
	"ID_ANIMAL_FK1" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
REM INSERTING into SARRA.ANIMAUX
SET DEFINE OFF;
REM INSERTING into SARRA.EMPLOYES
SET DEFINE OFF;
REM INSERTING into SARRA.FOURNIR
SET DEFINE OFF;
REM INSERTING into SARRA.MAGASINS
SET DEFINE OFF;
REM INSERTING into SARRA.PRENDRE_EN_CHARGE
SET DEFINE OFF;
REM INSERTING into SARRA.PRODUITS
SET DEFINE OFF;
REM INSERTING into SARRA.VISITES
SET DEFINE OFF;
Insert into SARRA.VISITES (IDENTIFIANTTICKET,PRIXTICKET,IDENTIFIANTVISITEUR,NOMBREVISITES,DATEVISITE,ABONNEMENT,ID_ANIMAL_FK1) values ('ml','75','23','2','lun. nov. 8 2021','Oui',null);
Insert into SARRA.VISITES (IDENTIFIANTTICKET,PRIXTICKET,IDENTIFIANTVISITEUR,NOMBREVISITES,DATEVISITE,ABONNEMENT,ID_ANIMAL_FK1) values ('mmpK','75','23','2','lun. nov. 8 2021','Oui',null);
Insert into SARRA.VISITES (IDENTIFIANTTICKET,PRIXTICKET,IDENTIFIANTVISITEUR,NOMBREVISITES,DATEVISITE,ABONNEMENT,ID_ANIMAL_FK1) values ('QS','75','23','2','lun. nov. 8 2021','Oui',null);
Insert into SARRA.VISITES (IDENTIFIANTTICKET,PRIXTICKET,IDENTIFIANTVISITEUR,NOMBREVISITES,DATEVISITE,ABONNEMENT,ID_ANIMAL_FK1) values ('PM','75','21','5','lun. nov. 8 2021','Oui',null);
Insert into SARRA.VISITES (IDENTIFIANTTICKET,PRIXTICKET,IDENTIFIANTVISITEUR,NOMBREVISITES,DATEVISITE,ABONNEMENT,ID_ANIMAL_FK1) values ('ll','8','7','0','lun. nov. 8 2021','Oui',null);
Insert into SARRA.VISITES (IDENTIFIANTTICKET,PRIXTICKET,IDENTIFIANTVISITEUR,NOMBREVISITES,DATEVISITE,ABONNEMENT,ID_ANIMAL_FK1) values ('sar','7','8','0','lun. nov. 8 2021','Oui',null);
Insert into SARRA.VISITES (IDENTIFIANTTICKET,PRIXTICKET,IDENTIFIANTVISITEUR,NOMBREVISITES,DATEVISITE,ABONNEMENT,ID_ANIMAL_FK1) values ('kl','5','4','0','lun. nov. 8 2021','Oui',null);
Insert into SARRA.VISITES (IDENTIFIANTTICKET,PRIXTICKET,IDENTIFIANTVISITEUR,NOMBREVISITES,DATEVISITE,ABONNEMENT,ID_ANIMAL_FK1) values ('ok','8','3','0','lun. nov. 8 2021','Oui',null);
Insert into SARRA.VISITES (IDENTIFIANTTICKET,PRIXTICKET,IDENTIFIANTVISITEUR,NOMBREVISITES,DATEVISITE,ABONNEMENT,ID_ANIMAL_FK1) values ('m','7','5','0','lun. nov. 8 2021','Oui',null);
Insert into SARRA.VISITES (IDENTIFIANTTICKET,PRIXTICKET,IDENTIFIANTVISITEUR,NOMBREVISITES,DATEVISITE,ABONNEMENT,ID_ANIMAL_FK1) values ('kh','65','2','0','lun. nov. 8 2021','Oui',null);
--------------------------------------------------------
--  DDL for Index ANIMAUX_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "SARRA"."ANIMAUX_PK" ON "SARRA"."ANIMAUX" ("ID_ANIMAL") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index EMPLOYES_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "SARRA"."EMPLOYES_PK" ON "SARRA"."EMPLOYES" ("ID_EMPLOYE") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index FOURNIR_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "SARRA"."FOURNIR_PK" ON "SARRA"."FOURNIR" ("ID_PRODUIT_PK1", "ID_ANIMAL_PK2") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index MAGASINS_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "SARRA"."MAGASINS_PK" ON "SARRA"."MAGASINS" ("ID_MAGASIN") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index PRENDRE_EN_CHARGE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "SARRA"."PRENDRE_EN_CHARGE_PK" ON "SARRA"."PRENDRE_EN_CHARGE" ("ID_ANIMAL_PK1", "ID_EMPLOYE_PK2") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index PRODUITS_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "SARRA"."PRODUITS_PK" ON "SARRA"."PRODUITS" ("ID_PRODUIT") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index VISITES_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "SARRA"."VISITES_PK" ON "SARRA"."VISITES" ("IDENTIFIANTTICKET") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  Constraints for Table ANIMAUX
--------------------------------------------------------

  ALTER TABLE "SARRA"."ANIMAUX" ADD CONSTRAINT "ANIMAUX_PK" PRIMARY KEY ("ID_ANIMAL")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "SARRA"."ANIMAUX" MODIFY ("ID_ANIMAL" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table EMPLOYES
--------------------------------------------------------

  ALTER TABLE "SARRA"."EMPLOYES" ADD CONSTRAINT "EMPLOYES_PK" PRIMARY KEY ("ID_EMPLOYE")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "SARRA"."EMPLOYES" MODIFY ("ID_EMPLOYE" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table FOURNIR
--------------------------------------------------------

  ALTER TABLE "SARRA"."FOURNIR" ADD CONSTRAINT "FOURNIR_PK" PRIMARY KEY ("ID_PRODUIT_PK1", "ID_ANIMAL_PK2")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "SARRA"."FOURNIR" MODIFY ("ID_ANIMAL_PK2" NOT NULL ENABLE);
  ALTER TABLE "SARRA"."FOURNIR" MODIFY ("ID_PRODUIT_PK1" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table MAGASINS
--------------------------------------------------------

  ALTER TABLE "SARRA"."MAGASINS" ADD CONSTRAINT "MAGASINS_PK" PRIMARY KEY ("ID_MAGASIN")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "SARRA"."MAGASINS" MODIFY ("ID_MAGASIN" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table PRENDRE_EN_CHARGE
--------------------------------------------------------

  ALTER TABLE "SARRA"."PRENDRE_EN_CHARGE" ADD CONSTRAINT "PRENDRE_EN_CHARGE_PK" PRIMARY KEY ("ID_ANIMAL_PK1", "ID_EMPLOYE_PK2")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "SARRA"."PRENDRE_EN_CHARGE" MODIFY ("ID_EMPLOYE_PK2" NOT NULL ENABLE);
  ALTER TABLE "SARRA"."PRENDRE_EN_CHARGE" MODIFY ("ID_ANIMAL_PK1" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table PRODUITS
--------------------------------------------------------

  ALTER TABLE "SARRA"."PRODUITS" ADD CONSTRAINT "PRODUITS_PK" PRIMARY KEY ("ID_PRODUIT")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "SARRA"."PRODUITS" MODIFY ("ID_PRODUIT" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table VISITES
--------------------------------------------------------

  ALTER TABLE "SARRA"."VISITES" ADD CONSTRAINT "VISITES_PK" PRIMARY KEY ("IDENTIFIANTTICKET")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "SARRA"."VISITES" MODIFY ("IDENTIFIANTTICKET" NOT NULL ENABLE);
--------------------------------------------------------
--  Ref Constraints for Table EMPLOYES
--------------------------------------------------------

  ALTER TABLE "SARRA"."EMPLOYES" ADD CONSTRAINT "EMPLOYES_FK1" FOREIGN KEY ("ID_EMPLOYE_FK1")
	  REFERENCES "SARRA"."EMPLOYES" ("ID_EMPLOYE") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table FOURNIR
--------------------------------------------------------

  ALTER TABLE "SARRA"."FOURNIR" ADD CONSTRAINT "FOURNIR_FK1" FOREIGN KEY ("ID_PRODUIT_PK1")
	  REFERENCES "SARRA"."ANIMAUX" ("ID_ANIMAL") ENABLE;
  ALTER TABLE "SARRA"."FOURNIR" ADD CONSTRAINT "FOURNIR_FK2" FOREIGN KEY ("ID_PRODUIT_PK1")
	  REFERENCES "SARRA"."PRODUITS" ("ID_PRODUIT") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table MAGASINS
--------------------------------------------------------

  ALTER TABLE "SARRA"."MAGASINS" ADD CONSTRAINT "MAGASINS_FK1" FOREIGN KEY ("ID_EMPLOYES_FK1")
	  REFERENCES "SARRA"."EMPLOYES" ("ID_EMPLOYE") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table PRENDRE_EN_CHARGE
--------------------------------------------------------

  ALTER TABLE "SARRA"."PRENDRE_EN_CHARGE" ADD CONSTRAINT "PRENDRE_EN_CHARGE_FK1" FOREIGN KEY ("ID_ANIMAL_PK1")
	  REFERENCES "SARRA"."ANIMAUX" ("ID_ANIMAL") ENABLE;
  ALTER TABLE "SARRA"."PRENDRE_EN_CHARGE" ADD CONSTRAINT "PRENDRE_EN_CHARGE_FK2" FOREIGN KEY ("ID_EMPLOYE_PK2")
	  REFERENCES "SARRA"."EMPLOYES" ("ID_EMPLOYE") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table VISITES
--------------------------------------------------------

  ALTER TABLE "SARRA"."VISITES" ADD CONSTRAINT "VISITES_FK1" FOREIGN KEY ("ID_ANIMAL_FK1")
	  REFERENCES "SARRA"."ANIMAUX" ("ID_ANIMAL") ENABLE;

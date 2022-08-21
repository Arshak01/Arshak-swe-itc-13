--
-- PostgreSQL database dump
--

-- Dumped from database version 14.4
-- Dumped by pg_dump version 14.4

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: agents; Type: TABLE; Schema: public; Owner: psqluser22
--

CREATE TABLE public.agents (
    id integer NOT NULL,
    name varchar(50) NOT NULL
);


ALTER TABLE public.agents OWNER TO psqluser22;

--
-- Name: agents_id_seq; Type: SEQUENCE; Schema: public; Owner: psqluser22
--

CREATE SEQUENCE public.agents_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.agents_id_seq OWNER TO psqluser22;

--
-- Name: agents_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: psqluser22
--

ALTER SEQUENCE public.agents_id_seq OWNED BY public.agents.id;


--
-- Name: branches; Type: TABLE; Schema: public; Owner: psqluser22
--

CREATE TABLE public.branches (
    id integer NOT NULL,
    name varchar(50) NOT NULL
);


ALTER TABLE public.branches OWNER TO psqluser22;

--
-- Name: branches_id_seq; Type: SEQUENCE; Schema: public; Owner: psqluser22
--

CREATE SEQUENCE public.branches_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.branches_id_seq OWNER TO psqluser22;

--
-- Name: branches_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: psqluser22
--

ALTER SEQUENCE public.branches_id_seq OWNED BY public.branches.id;


--
-- Name: countries; Type: TABLE; Schema: public; Owner: psqluser22
--

CREATE TABLE public.countries (
    id integer NOT NULL,
    name varchar(50) NOT NULL
);


ALTER TABLE public.countries OWNER TO psqluser22;

--
-- Name: countries_id_seq; Type: SEQUENCE; Schema: public; Owner: psqluser22
--

CREATE SEQUENCE public.countries_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.countries_id_seq OWNER TO psqluser22;

--
-- Name: countries_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: psqluser22
--

ALTER SEQUENCE public.countries_id_seq OWNED BY public.countries.id;


--
-- Name: customers; Type: TABLE; Schema: public; Owner: psqluser22
--

CREATE TABLE public.customers (
    id integer NOT NULL,
    name varchar(50) NOT NULL,
    email varchar(50),
    contact_phone json,
    address varchar(50),
    about varchar(255)
);


ALTER TABLE public.customers OWNER TO psqluser22;

--
-- Name: customers_id_seq; Type: SEQUENCE; Schema: public; Owner: psqluser22
--

CREATE SEQUENCE public.customers_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.customers_id_seq OWNER TO psqluser22;

--
-- Name: customers_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: psqluser22
--

ALTER SEQUENCE public.customers_id_seq OWNED BY public.customers.id;


--
-- Name: daily_saved_employee_histories; Type: TABLE; Schema: public; Owner: psqluser22
--

CREATE TABLE public.daily_saved_employee_histories (
    id integer NOT NULL,
    start_date timestamp with time zone NOT NULL,
    updated_status varchar(25) NOT NULL,
    updated_rate real NOT NULL,
    employee_id integer NOT NULL,
    "createdAt" timestamp with time zone NOT NULL,
    "updatedAt" timestamp with time zone NOT NULL
);


ALTER TABLE public.daily_saved_employee_histories OWNER TO psqluser22;

--
-- Name: daily_saved_employee_histories_id_seq; Type: SEQUENCE; Schema: public; Owner: psqluser22
--

CREATE SEQUENCE public.daily_saved_employee_histories_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.daily_saved_employee_histories_id_seq OWNER TO psqluser22;

--
-- Name: daily_saved_employee_histories_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: psqluser22
--

ALTER SEQUENCE public.daily_saved_employee_histories_id_seq OWNED BY public.daily_saved_employee_histories.id;


--
-- Name: employee_allocations; Type: TABLE; Schema: public; Owner: psqluser22
--

CREATE TABLE public.employee_allocations (
    id integer NOT NULL,
    start_date timestamp with time zone NOT NULL,
    end_date timestamp with time zone,
    rate real NOT NULL,
    role_id integer NOT NULL,
    project_id integer NOT NULL,
    employee_id integer NOT NULL
);


ALTER TABLE public.employee_allocations OWNER TO psqluser22;

--
-- Name: employee_allocations_id_seq; Type: SEQUENCE; Schema: public; Owner: psqluser22
--

CREATE SEQUENCE public.employee_allocations_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.employee_allocations_id_seq OWNER TO psqluser22;

--
-- Name: employee_allocations_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: psqluser22
--

ALTER SEQUENCE public.employee_allocations_id_seq OWNED BY public.employee_allocations.id;


--
-- Name: employees; Type: TABLE; Schema: public; Owner: psqluser22
--

CREATE TABLE public.employees (
    id integer NOT NULL,
    planned_rate real NOT NULL,
    actual_rate real NOT NULL,
    month timestamp with time zone NOT NULL,
    branch_id integer NOT NULL,
    unit_id integer NOT NULL,
    position_id integer NOT NULL,
    status_id integer NOT NULL,
    hr_employee_id integer NOT NULL
);


ALTER TABLE public.employees OWNER TO psqluser22;

--
-- Name: employees_id_seq; Type: SEQUENCE; Schema: public; Owner: psqluser22
--

CREATE SEQUENCE public.employees_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.employees_id_seq OWNER TO psqluser22;

--
-- Name: employees_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: psqluser22
--

ALTER SEQUENCE public.employees_id_seq OWNED BY public.employees.id;


--
-- Name: engagement_categories; Type: TABLE; Schema: public; Owner: psqluser22
--

CREATE TABLE public.engagement_categories (
    id integer NOT NULL,
    name varchar(25) DEFAULT ''::bpchar NOT NULL
);


ALTER TABLE public.engagement_categories OWNER TO psqluser22;

--
-- Name: engagement_categories_id_seq; Type: SEQUENCE; Schema: public; Owner: psqluser22
--

CREATE SEQUENCE public.engagement_categories_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.engagement_categories_id_seq OWNER TO psqluser22;

--
-- Name: engagement_categories_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: psqluser22
--

ALTER SEQUENCE public.engagement_categories_id_seq OWNED BY public.engagement_categories.id;


--
-- Name: engagement_informations; Type: TABLE; Schema: public; Owner: psqluser22
--

CREATE TABLE public.engagement_informations (
    id integer NOT NULL,
    start_date timestamp with time zone NOT NULL,
    end_date timestamp with time zone,
    project_id integer NOT NULL,
    "createdAt" timestamp with time zone NOT NULL,
    "updatedAt" timestamp with time zone NOT NULL
);


ALTER TABLE public.engagement_informations OWNER TO psqluser22;

--
-- Name: engagement_informations_id_seq; Type: SEQUENCE; Schema: public; Owner: psqluser22
--

CREATE SEQUENCE public.engagement_informations_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.engagement_informations_id_seq OWNER TO psqluser22;

--
-- Name: engagement_informations_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: psqluser22
--

ALTER SEQUENCE public.engagement_informations_id_seq OWNED BY public.engagement_informations.id;


--
-- Name: engagement_models; Type: TABLE; Schema: public; Owner: psqluser22
--

CREATE TABLE public.engagement_models (
    id integer NOT NULL,
    name varchar(25) NOT NULL
);


ALTER TABLE public.engagement_models OWNER TO psqluser22;

--
-- Name: engagement_models_id_seq; Type: SEQUENCE; Schema: public; Owner: psqluser22
--

CREATE SEQUENCE public.engagement_models_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.engagement_models_id_seq OWNER TO psqluser22;

--
-- Name: engagement_models_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: psqluser22
--

ALTER SEQUENCE public.engagement_models_id_seq OWNED BY public.engagement_models.id;


--
-- Name: hr_employees; Type: TABLE; Schema: public; Owner: psqluser22
--

CREATE TABLE public.hr_employees (
    id integer NOT NULL,
    in_combination boolean NOT NULL,
    short_profile varchar(75) NOT NULL,
    name varchar(50) NOT NULL,
    surname varchar(50) NOT NULL,
    email varchar(50) NOT NULL,
    contact_phone varchar(25) NOT NULL,
    date_of_birth timestamp with time zone NOT NULL,
    gender_id integer NOT NULL,
    social_id varchar(25) NOT NULL,
    image varchar(255) NOT NULL,
    id_namber varchar(40) NOT NULL,
    id_document_type integer NOT NULL,
    profassion varchar(50) NOT NULL,
    family_status integer NOT NULL,
    bank_account varchar(30) NOT NULL
);


ALTER TABLE public.hr_employees OWNER TO psqluser22;

--
-- Name: hr_employees_id_seq; Type: SEQUENCE; Schema: public; Owner: psqluser22
--

CREATE SEQUENCE public.hr_employees_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.hr_employees_id_seq OWNER TO psqluser22;

--
-- Name: hr_employees_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: psqluser22
--

ALTER SEQUENCE public.hr_employees_id_seq OWNED BY public.hr_employees.id;


--
-- Name: monthly_saved_employee_histories; Type: TABLE; Schema: public; Owner: psqluser22
--

CREATE TABLE public.monthly_saved_employee_histories (
    id integer,
    updated_branch varchar(50) NOT NULL,
    updated_position varchar(50) NOT NULL,
    start_month timestamp with time zone NOT NULL,
    "createdAt" timestamp with time zone NOT NULL,
    "updatedAt" timestamp with time zone NOT NULL
);


ALTER TABLE public.monthly_saved_employee_histories OWNER TO psqluser22;

--
-- Name: positions; Type: TABLE; Schema: public; Owner: psqluser22
--

CREATE TABLE public.positions (
    id integer NOT NULL,
    name varchar(50) NOT NULL,
    min_rate real NOT NULL,
    min_experiance real NOT NULL
);


ALTER TABLE public.positions OWNER TO psqluser22;

--
-- Name: positions_id_seq; Type: SEQUENCE; Schema: public; Owner: psqluser22
--

CREATE SEQUENCE public.positions_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.positions_id_seq OWNER TO psqluser22;

--
-- Name: positions_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: psqluser22
--

ALTER SEQUENCE public.positions_id_seq OWNED BY public.positions.id;


--
-- Name: project_histories; Type: TABLE; Schema: public; Owner: psqluser22
--

CREATE TABLE public.project_histories (
    id integer,
    start_date timestamp with time zone NOT NULL,
    updated_confidential_type_id integer,
    updated_category varchar(25) NOT NULL,
    updated_model varchar(25) NOT NULL,
    updated_activity boolean NOT NULL,
    updated_budget varchar(25),
    "createdAt" timestamp with time zone NOT NULL,
    "updatedAt" timestamp with time zone NOT NULL
);


ALTER TABLE public.project_histories OWNER TO psqluser22;

--
-- Name: project_needs; Type: TABLE; Schema: public; Owner: psqluser22
--

CREATE TABLE public.project_needs (
    id integer NOT NULL,
    amount integer,
    start_date timestamp with time zone NOT NULL,
    end_date timestamp with time zone,
    link varchar(50),
    employee_count_change integer NOT NULL,
    project_id integer NOT NULL,
    resource_id integer,
    unit_id integer NOT NULL,
    "createdAt" timestamp with time zone NOT NULL,
    "updatedAt" timestamp with time zone NOT NULL
);


ALTER TABLE public.project_needs OWNER TO psqluser22;

--
-- Name: project_needs_id_seq; Type: SEQUENCE; Schema: public; Owner: psqluser22
--

CREATE SEQUENCE public.project_needs_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.project_needs_id_seq OWNER TO psqluser22;

--
-- Name: project_needs_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: psqluser22
--

ALTER SEQUENCE public.project_needs_id_seq OWNED BY public.project_needs.id;


--
-- Name: projects; Type: TABLE; Schema: public; Owner: psqluser22
--

CREATE TABLE public.projects (
    id integer NOT NULL,
    name varchar(50) NOT NULL,
    start_date timestamp with time zone NOT NULL,
    end_date timestamp with time zone,
    about varchar(255),
    technology_tools varchar(255),
    budget varchar(25),
    confidential_type_id integer,
    logo_url varchar(25),
    is_active boolean DEFAULT false NOT NULL,
    achievements_report boolean DEFAULT false,
    is_billable boolean DEFAULT false NOT NULL,
    customer_id integer NOT NULL,
    agent_id integer,
    category_id integer NOT NULL,
    model_id integer NOT NULL,
    country_id integer
);


ALTER TABLE public.projects OWNER TO psqluser22;

--
-- Name: projects_id_seq; Type: SEQUENCE; Schema: public; Owner: psqluser22
--

CREATE SEQUENCE public.projects_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.projects_id_seq OWNER TO psqluser22;

--
-- Name: projects_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: psqluser22
--

ALTER SEQUENCE public.projects_id_seq OWNED BY public.projects.id;


--
-- Name: requested_resources; Type: TABLE; Schema: public; Owner: psqluser22
--

CREATE TABLE public.requested_resources (
    id integer NOT NULL,
    name varchar(50) NOT NULL
);


ALTER TABLE public.requested_resources OWNER TO psqluser22;

--
-- Name: requested_resources_id_seq; Type: SEQUENCE; Schema: public; Owner: psqluser22
--

CREATE SEQUENCE public.requested_resources_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.requested_resources_id_seq OWNER TO psqluser22;

--
-- Name: requested_resources_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: psqluser22
--

ALTER SEQUENCE public.requested_resources_id_seq OWNED BY public.requested_resources.id;


--
-- Name: roles; Type: TABLE; Schema: public; Owner: psqluser22
--

CREATE TABLE public.roles (
    id integer NOT NULL,
    name varchar(25) NOT NULL
);


ALTER TABLE public.roles OWNER TO psqluser22;

--
-- Name: roles_id_seq; Type: SEQUENCE; Schema: public; Owner: psqluser22
--

CREATE SEQUENCE public.roles_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.roles_id_seq OWNER TO psqluser22;

--
-- Name: roles_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: psqluser22
--

ALTER SEQUENCE public.roles_id_seq OWNED BY public.roles.id;


--
-- Name: confidential_types; Type: TABLE; Schema: public; Owner: psqluser22
--

CREATE TABLE public.confidential_types (
    id integer NOT NULL,
    name varchar(25) NOT NULL
);


ALTER TABLE public.confidential_types OWNER TO psqluser22;

--
-- Name: confidential_types_id_seq; Type: SEQUENCE; Schema: public; Owner: psqluser22
--

CREATE SEQUENCE public.confidential_types_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.confidential_types_id_seq OWNER TO psqluser22;

--
-- Name: confidential_types_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: psqluser22
--

ALTER SEQUENCE public.confidential_types_id_seq OWNED BY public.confidential_types.id;

--
-- Name: statuses; Type: TABLE; Schema: public; Owner: psqluser22
--

CREATE TABLE public.statuses (
    id integer NOT NULL,
    name varchar(50) NOT NULL
);


ALTER TABLE public.statuses OWNER TO psqluser22;

--
-- Name: statuses_id_seq; Type: SEQUENCE; Schema: public; Owner: psqluser22
--

CREATE SEQUENCE public.statuses_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.statuses_id_seq OWNER TO psqluser22;

--
-- Name: statuses_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: psqluser22
--

ALTER SEQUENCE public.statuses_id_seq OWNED BY public.statuses.id;


--
-- Name: units; Type: TABLE; Schema: public; Owner: psqluser22
--

CREATE TABLE public.units (
    id integer NOT NULL,
    name varchar(25) NOT NULL
);


ALTER TABLE public.units OWNER TO psqluser22;

--
-- Name: units_id_seq; Type: SEQUENCE; Schema: public; Owner: psqluser22
--

CREATE SEQUENCE public.units_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.units_id_seq OWNER TO psqluser22;

--
-- Name: units_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: psqluser22
--

ALTER SEQUENCE public.units_id_seq OWNED BY public.units.id;


--
-- Name: agents id; Type: DEFAULT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.agents ALTER COLUMN id SET DEFAULT nextval('public.agents_id_seq'::regclass);


--
-- Name: branches id; Type: DEFAULT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.branches ALTER COLUMN id SET DEFAULT nextval('public.branches_id_seq'::regclass);


--
-- Name: countries id; Type: DEFAULT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.countries ALTER COLUMN id SET DEFAULT nextval('public.countries_id_seq'::regclass);


--
-- Name: customers id; Type: DEFAULT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.customers ALTER COLUMN id SET DEFAULT nextval('public.customers_id_seq'::regclass);


--
-- Name: daily_saved_employee_histories id; Type: DEFAULT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.daily_saved_employee_histories ALTER COLUMN id SET DEFAULT nextval('public.daily_saved_employee_histories_id_seq'::regclass);


--
-- Name: employee_allocations id; Type: DEFAULT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.employee_allocations ALTER COLUMN id SET DEFAULT nextval('public.employee_allocations_id_seq'::regclass);


--
-- Name: employees id; Type: DEFAULT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.employees ALTER COLUMN id SET DEFAULT nextval('public.employees_id_seq'::regclass);


--
-- Name: engagement_categories id; Type: DEFAULT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.engagement_categories ALTER COLUMN id SET DEFAULT nextval('public.engagement_categories_id_seq'::regclass);


--
-- Name: engagement_informations id; Type: DEFAULT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.engagement_informations ALTER COLUMN id SET DEFAULT nextval('public.engagement_informations_id_seq'::regclass);


--
-- Name: engagement_models id; Type: DEFAULT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.engagement_models ALTER COLUMN id SET DEFAULT nextval('public.engagement_models_id_seq'::regclass);


--
-- Name: hr_employees id; Type: DEFAULT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.hr_employees ALTER COLUMN id SET DEFAULT nextval('public.hr_employees_id_seq'::regclass);


--
-- Name: positions id; Type: DEFAULT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.positions ALTER COLUMN id SET DEFAULT nextval('public.positions_id_seq'::regclass);


--
-- Name: project_needs id; Type: DEFAULT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.project_needs ALTER COLUMN id SET DEFAULT nextval('public.project_needs_id_seq'::regclass);


--
-- Name: projects id; Type: DEFAULT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.projects ALTER COLUMN id SET DEFAULT nextval('public.projects_id_seq'::regclass);


--
-- Name: requested_resources id; Type: DEFAULT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.requested_resources ALTER COLUMN id SET DEFAULT nextval('public.requested_resources_id_seq'::regclass);


--
-- Name: roles id; Type: DEFAULT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.roles ALTER COLUMN id SET DEFAULT nextval('public.roles_id_seq'::regclass);

--
-- Name: confidential_types id; Type: DEFAULT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.confidential_types ALTER COLUMN id SET DEFAULT nextval('public.confidential_types_id_seq'::regclass);
--
-- Name: statuses id; Type: DEFAULT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.statuses ALTER COLUMN id SET DEFAULT nextval('public.statuses_id_seq'::regclass);


--
-- Name: units id; Type: DEFAULT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.units ALTER COLUMN id SET DEFAULT nextval('public.units_id_seq'::regclass);


--
-- Data for Name: agents; Type: TABLE DATA; Schema: public; Owner: psqluser22
--

COPY public.agents (id, name) FROM stdin;
1	Lafin-Rick Ader
\.


--
-- Data for Name: branches; Type: TABLE DATA; Schema: public; Owner: psqluser22
--

COPY public.branches (id, name) FROM stdin;
1	Yerevan
2	Vanadzor
3	Stepanakert
4	Gyumri
5	Goris
6	Kapan
\.


--
-- Data for Name: countries; Type: TABLE DATA; Schema: public; Owner: psqluser22
--

COPY public.countries (id, name) FROM stdin;
1	United Kingdom
2	United State
3	Armenia
\.


--
-- Data for Name: customers; Type: TABLE DATA; Schema: public; Owner: psqluser22
--

COPY public.customers (id, name, email, contact_phone, address, about) FROM stdin;
1	Accelerate Group Limited	info@webtrends.com	\N	\N	\N
2	Instigate Mobile	info@instigatemobile.com	{"short":"US"}	Shirakatsi 1, Vanadzor, Armenia	\N
\.


--
-- Data for Name: daily_saved_employee_histories; Type: TABLE DATA; Schema: public; Owner: psqluser22
--

COPY public.daily_saved_employee_histories (id, start_date, updated_status, updated_rate, employee_id, "createdAt", "updatedAt") FROM stdin;
\.


--
-- Data for Name: employees; Type: TABLE DATA; Schema: public; Owner: psqluser22
--

COPY public.employees (id, planned_rate, actual_rate, month, branch_id, unit_id, position_id, status_id, hr_employee_id) FROM stdin;
3	1	1	2022-07-11 14:44:05.536989+04	2	1	6	1	2
4	1	1	2022-07-11 14:44:24.714856+04	1	2	6	1	3
2	1	1	2022-07-11 14:44:45.382567+04	1	2	4	1	4
\.


--
-- Data for Name: engagement_categories; Type: TABLE DATA; Schema: public; Owner: psqluser22
--

COPY public.engagement_categories (id, name) FROM stdin;
1	Billable
2	Internal Investment
3	Admin
4	Presales
5	Internal
\.


--
-- Data for Name: engagement_informations; Type: TABLE DATA; Schema: public; Owner: psqluser22
--

COPY public.engagement_informations (id, start_date, end_date, project_id, "createdAt", "updatedAt") FROM stdin;
\.


--
-- Data for Name: engagement_models; Type: TABLE DATA; Schema: public; Owner: psqluser22
--

COPY public.engagement_models (id, name) FROM stdin;
1	Time and Material
2	Milestone
3	None
\.


--
-- Data for Name: hr_employees; Type: TABLE DATA; Schema: public; Owner: psqluser22
--

COPY public.hr_employees (id, in_combination, short_profile, name, surname, email, contact_phone, date_of_birth, gender_id, social_id, image, id_namber, id_document_type, profassion, family_status, bank_account) FROM stdin;
2	t		Anzhela	Andreasyan	anjela@instigatemobile.com	+374	1992-11-04 00:00:00+03	1	***		***	1		1	***
3	t		Naira	Khurshudya	naira@instigatemobile.com	+374	1992-11-04 00:00:00+03	1	***		***	1		1	***
4	t		Artyom	Gasparyan	artyom@instigatemobile.com	+374	1992-11-04 00:00:00+03	1	***		***	1		1	***
\.


--
-- Data for Name: monthly_saved_employee_histories; Type: TABLE DATA; Schema: public; Owner: psqluser22
--

COPY public.monthly_saved_employee_histories (id, updated_branch, updated_position, start_month, "createdAt", "updatedAt") FROM stdin;
\.


--
-- Data for Name: positions; Type: TABLE DATA; Schema: public; Owner: psqluser22
--

COPY public.positions (id, name, min_rate, min_experiance) FROM stdin;
4	Project Manager, Mid	0.3	3
5	SW Engineer, Senior 1	1	3
6	Director, SW Engineering	1	5
\.


--
-- Data for Name: project_histories; Type: TABLE DATA; Schema: public; Owner: psqluser22
--

COPY public.project_histories (id, start_date, updated_confidential_type_id, updated_category, updated_model, updated_activity, updated_budget, "createdAt", "updatedAt") FROM stdin;
\.


--
-- Data for Name: project_needs; Type: TABLE DATA; Schema: public; Owner: psqluser22
--

COPY public.project_needs (id, amount, start_date, end_date, link, employee_count_change, project_id, resource_id, unit_id, "createdAt", "updatedAt") FROM stdin;
\.


--
-- Data for Name: projects; Type: TABLE DATA; Schema: public; Owner: psqluser22
--

COPY public.projects (id, name, start_date, end_date, about, technology_tools, budget, logo_url, is_active, achievements_report, is_billable, customer_id, agent_id, category_id, model_id, country_id) FROM stdin;
1	Project Matrix	2022-05-01 14:52:26.056+04	\N	\N	\N	\N                      	\N	f	t	f	1	\N	5	1	3
2	Skill Matrix	2022-07-01 20:53:41.16+04	\N	\N	\N	\N	\N	f	f	f	1	\N	5	1	\N
\.


--
-- Data for Name: requested_resources; Type: TABLE DATA; Schema: public; Owner: psqluser22
--

COPY public.requested_resources (id, name) FROM stdin;
\.


--
-- Data for Name: roles; Type: TABLE DATA; Schema: public; Owner: psqluser22
--

COPY public.roles (id, name) FROM stdin;
1	thread
2	pair
3	account lead
4	team lead
5	project manager
\.

--
-- Data for Name: confidential_types; Type: TABLE DATA; Schema: public; Owner: psqluser22
--

COPY public.confidential_types (id, name) FROM stdin;
1	Standard
2	On Request
3	Strictly Private
\.


--
-- Data for Name: statuses; Type: TABLE DATA; Schema: public; Owner: psqluser22
--

COPY public.statuses (id, name) FROM stdin;
1	Employed
5	Maternity leave
\.


--
-- Data for Name: units; Type: TABLE DATA; Schema: public; Owner: psqluser22
--

COPY public.units (id, name) FROM stdin;
1	Vanadzor/Gyumri
2	Yerevan/Stepanakert
3	Goris/Kapan
\.


--
-- Name: agents_id_seq; Type: SEQUENCE SET; Schema: public; Owner: psqluser22
--

SELECT pg_catalog.setval('public.agents_id_seq', 1, true);


--
-- Name: branches_id_seq; Type: SEQUENCE SET; Schema: public; Owner: psqluser22
--

SELECT pg_catalog.setval('public.branches_id_seq', 6, true);


--
-- Name: countries_id_seq; Type: SEQUENCE SET; Schema: public; Owner: psqluser22
--

SELECT pg_catalog.setval('public.countries_id_seq', 3, true);


--
-- Name: customers_id_seq; Type: SEQUENCE SET; Schema: public; Owner: psqluser22
--

SELECT pg_catalog.setval('public.customers_id_seq', 2, true);


--
-- Name: daily_saved_employee_histories_id_seq; Type: SEQUENCE SET; Schema: public; Owner: psqluser22
--

SELECT pg_catalog.setval('public.daily_saved_employee_histories_id_seq', 1, false);


--
-- Name: employee_allocations_id_seq; Type: SEQUENCE SET; Schema: public; Owner: psqluser22
--

SELECT pg_catalog.setval('public.employee_allocations_id_seq', 1, true);


--
-- Name: employees_id_seq; Type: SEQUENCE SET; Schema: public; Owner: psqluser22
--

SELECT pg_catalog.setval('public.employees_id_seq', 5, true);


--
-- Name: engagement_categories_id_seq; Type: SEQUENCE SET; Schema: public; Owner: psqluser22
--

SELECT pg_catalog.setval('public.engagement_categories_id_seq', 5, true);


--
-- Name: engagement_informations_id_seq; Type: SEQUENCE SET; Schema: public; Owner: psqluser22
--

SELECT pg_catalog.setval('public.engagement_informations_id_seq', 1, false);


--
-- Name: engagement_models_id_seq; Type: SEQUENCE SET; Schema: public; Owner: psqluser22
--

SELECT pg_catalog.setval('public.engagement_models_id_seq', 3, true);


--
-- Name: hr_employees_id_seq; Type: SEQUENCE SET; Schema: public; Owner: psqluser22
--

SELECT pg_catalog.setval('public.hr_employees_id_seq', 4, true);


--
-- Name: positions_id_seq; Type: SEQUENCE SET; Schema: public; Owner: psqluser22
--

SELECT pg_catalog.setval('public.positions_id_seq', 6, true);


--
-- Name: project_needs_id_seq; Type: SEQUENCE SET; Schema: public; Owner: psqluser22
--

SELECT pg_catalog.setval('public.project_needs_id_seq', 1, false);


--
-- Name: projects_id_seq; Type: SEQUENCE SET; Schema: public; Owner: psqluser22
--

SELECT pg_catalog.setval('public.projects_id_seq', 2, true);


--
-- Name: requested_resources_id_seq; Type: SEQUENCE SET; Schema: public; Owner: psqluser22
--

SELECT pg_catalog.setval('public.requested_resources_id_seq', 1, false);


--
-- Name: roles_id_seq; Type: SEQUENCE SET; Schema: public; Owner: psqluser22
--

SELECT pg_catalog.setval('public.roles_id_seq', 5, true);

--
-- Name: confidential_types_id_seq; Type: SEQUENCE SET; Schema: public; Owner: psqluser22
--

SELECT pg_catalog.setval('public.confidential_types_id_seq', 5, true);



--
-- Name: statuses_id_seq; Type: SEQUENCE SET; Schema: public; Owner: psqluser22
--

SELECT pg_catalog.setval('public.statuses_id_seq', 5, true);


--
-- Name: units_id_seq; Type: SEQUENCE SET; Schema: public; Owner: psqluser22
--

SELECT pg_catalog.setval('public.units_id_seq', 3, true);


--
-- Name: agents agents_pkey; Type: CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.agents
    ADD CONSTRAINT agents_pkey PRIMARY KEY (id);


--
-- Name: branches branches_pkey; Type: CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.branches
    ADD CONSTRAINT branches_pkey PRIMARY KEY (id);


--
-- Name: countries countries_pkey; Type: CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.countries
    ADD CONSTRAINT countries_pkey PRIMARY KEY (id);


--
-- Name: customers customers_pkey; Type: CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.customers
    ADD CONSTRAINT customers_pkey PRIMARY KEY (id);


--
-- Name: daily_saved_employee_histories daily_saved_employee_histories_pkey; Type: CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.daily_saved_employee_histories
    ADD CONSTRAINT daily_saved_employee_histories_pkey PRIMARY KEY (id);


--
-- Name: employee_allocations employee_allocations_pkey; Type: CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.employee_allocations
    ADD CONSTRAINT employee_allocations_pkey PRIMARY KEY (id);


--
-- Name: employees employees_pkey; Type: CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.employees
    ADD CONSTRAINT employees_pkey PRIMARY KEY (id);


--
-- Name: engagement_categories engagement_categories_pkey; Type: CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.engagement_categories
    ADD CONSTRAINT engagement_categories_pkey PRIMARY KEY (id);


--
-- Name: engagement_informations engagement_informations_pkey; Type: CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.engagement_informations
    ADD CONSTRAINT engagement_informations_pkey PRIMARY KEY (id);


--
-- Name: engagement_models engagement_models_pkey; Type: CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.engagement_models
    ADD CONSTRAINT engagement_models_pkey PRIMARY KEY (id);


--
-- Name: hr_employees hr_employees_pkey; Type: CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.hr_employees
    ADD CONSTRAINT hr_employees_pkey PRIMARY KEY (id);


--
-- Name: positions positions_pkey; Type: CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.positions
    ADD CONSTRAINT positions_pkey PRIMARY KEY (id);


--
-- Name: project_needs project_needs_pkey; Type: CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.project_needs
    ADD CONSTRAINT project_needs_pkey PRIMARY KEY (id);


--
-- Name: projects projects_pkey; Type: CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.projects
    ADD CONSTRAINT projects_pkey PRIMARY KEY (id);


--
-- Name: requested_resources requested_resources_pkey; Type: CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.requested_resources
    ADD CONSTRAINT requested_resources_pkey PRIMARY KEY (id);


--
-- Name: roles roles_pkey; Type: CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.roles
    ADD CONSTRAINT roles_pkey PRIMARY KEY (id);

--
-- Name: confidential_types confidential_types_pkey; Type: CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.confidential_types
    ADD CONSTRAINT confidential_types_pkey PRIMARY KEY (id);

--
-- Name: statuses statuses_pkey; Type: CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.statuses
    ADD CONSTRAINT statuses_pkey PRIMARY KEY (id);


--
-- Name: units units_pkey; Type: CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.units
    ADD CONSTRAINT units_pkey PRIMARY KEY (id);


--
-- Name: daily_saved_employee_histories daily_saved_employee_histories_employee_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.daily_saved_employee_histories
    ADD CONSTRAINT daily_saved_employee_histories_employee_id_fkey FOREIGN KEY (employee_id) REFERENCES public.employees(id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: employee_allocations employee_allocations_project_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.employee_allocations
    ADD CONSTRAINT employee_allocations_project_id_fkey FOREIGN KEY (project_id) REFERENCES public.projects(id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: employee_allocations employee_allocations_role_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.employee_allocations
    ADD CONSTRAINT employee_allocations_role_id_fkey FOREIGN KEY (role_id) REFERENCES public.roles(id) ON UPDATE CASCADE ON DELETE CASCADE;

--
-- Name: projects projects_confidential_type_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.projects
    ADD CONSTRAINT projects_confidential_type_id_fkey FOREIGN KEY (confidential_type_id) REFERENCES public.confidential_types(id) ON UPDATE CASCADE ON DELETE CASCADE;

--
-- Name: employees employees_branch_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.employees
    ADD CONSTRAINT employees_branch_id_fkey FOREIGN KEY (branch_id) REFERENCES public.branches(id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: employees employees_hr_employee_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.employees
    ADD CONSTRAINT employees_hr_employee_id_fkey FOREIGN KEY (hr_employee_id) REFERENCES public.hr_employees(id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: employees employees_position_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.employees
    ADD CONSTRAINT employees_position_id_fkey FOREIGN KEY (position_id) REFERENCES public.positions(id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: employees employees_status_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.employees
    ADD CONSTRAINT employees_status_id_fkey FOREIGN KEY (status_id) REFERENCES public.statuses(id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: engagement_informations engagement_informations_project_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.engagement_informations
    ADD CONSTRAINT engagement_informations_project_id_fkey FOREIGN KEY (project_id) REFERENCES public.projects(id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: monthly_saved_employee_histories monthly_saved_employee_histories_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.monthly_saved_employee_histories
    ADD CONSTRAINT monthly_saved_employee_histories_id_fkey FOREIGN KEY (id) REFERENCES public.employees(id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: project_histories project_histories_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.project_histories
    ADD CONSTRAINT project_histories_id_fkey FOREIGN KEY (id) REFERENCES public.projects(id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: project_needs project_needs_resource_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.project_needs
    ADD CONSTRAINT project_needs_resource_id_fkey FOREIGN KEY (resource_id) REFERENCES public.requested_resources(id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: project_needs project_needs_unit_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.project_needs
    ADD CONSTRAINT project_needs_unit_id_fkey FOREIGN KEY (unit_id) REFERENCES public.units(id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: projects projects_agent_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.projects
    ADD CONSTRAINT projects_agent_id_fkey FOREIGN KEY (agent_id) REFERENCES public.agents(id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: projects projects_category_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.projects
    ADD CONSTRAINT projects_category_id_fkey FOREIGN KEY (category_id) REFERENCES public.engagement_categories(id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: projects projects_country_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.projects
    ADD CONSTRAINT projects_country_id_fkey FOREIGN KEY (country_id) REFERENCES public.countries(id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: projects projects_customer_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.projects
    ADD CONSTRAINT projects_customer_id_fkey FOREIGN KEY (customer_id) REFERENCES public.customers(id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: projects projects_model_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: psqluser22
--

ALTER TABLE ONLY public.projects
    ADD CONSTRAINT projects_model_id_fkey FOREIGN KEY (model_id) REFERENCES public.engagement_models(id) ON UPDATE CASCADE ON DELETE CASCADE;

--
-- PostgreSQL database dump complete
--


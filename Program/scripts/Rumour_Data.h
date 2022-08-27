#define SIMPLE_RUMOUR_NUM	13
string DEFAULT_TEXT[30] = {
"Говорят, что раз-два в год из Порто Белло  отправляется  так  называемый  Золотой флот - караван из нескольких десятков  торговых  судов  под  охраной  боевых кораблей. Он следует всегда одним и  тем  же,  неизменным,  раз  и  навсегда установленным, маршрутом: выйдя из испанской гавани  Порто Белло, он берет курс на север, к Гаване. А затем через Атлантику в Европу. Не стоит и говорить о том, что на борту кораблей Золотого флота находятся несметные сокровища.",
"Вы знаете, что когда чей-то флот атакует колонию, можно помочь её захватить - надо подплыть к флагману атакующей эскадры, выслать на него шлюпку и договориться об условиях с адмиралом.",
"Оказывается, когда чей-то флот атакует колонию, можно  помочь её обороне, зайти через джунгли в город и поговорить с губернатором об условиях помощи в обороне колонии от нападающих.",
"Иногда, важные сведения можно получить в таверне от посетителей или прислуги. Так как любой приезжий перво-наперво заходит именно в трактир.",
"Чтобы попасть во враждебный город, можно высадиться в ближайшей бухте и через джунгли пробраться к городским воротам. Но лучше это сделать под покровом темноты.",
"Капитан, если ты захватил в плен вражеского капитана, не спеши расправляться с ним! Так как за богатого пленника всегда можно получить хороший выкуп. Или можно просто высадить его на каком-нибудь пустынном берегу.",
"Климат у нас тут жаркий и влажный, но с апреля по октябрь начинается сезон дождей с тропическими ливнями и суровыми штормами. Никому не пожелаю попасть в такой шторм в открытом море!",
"Чтобы выгодно торговать, нужно знать выгодные торговые маршруты, иметь деловую хватку, а где-то  приятельские отношения с владельцами магазинов. Также хороший казначей здорово помогает в торговых делах.",
"Капитан, помни, что в морском бою самый страшный залп - бортовой, поэтому старайся всегда стрелять по врагу из боковых орудий, но сам, при этом, старайся не подставляться под бортовой залп противника.",
"Иногда лучше избежать морского боя с превосходящими силами противника, но чтобы уйти от врагов, нужно быть очень быстрым. Когда ситуация безвыходная и нужно спасаться бегством, то лучше выбросить груз из трюма, тем самым облегчив судно, что позволит развить большую скорость и уйти от погони.",
"Те, кто решили заняться пиратством, могут получить ценные сведения о богатых купцах в таверне. Но не всякому завсегдатаи трактира расскажут о легкой добыче. Только человек с темным прошлым может рассчитывать на подобную услугу. Хотя золото, как известно, открывает любые двери.",
"Чтобы получить расположение генерал-губернатора, а заодно и каперский патент одной из стран, необходимо доказать свою преданность примерной службой губернатору одной из колоний этой страны. Хотя бывали случаи, когда известные пираты становились каперами, попросту купив патент у нечистых на руку агентов.",
"За голову дерзкого пирата или лихого разбойника колониальные власти частенько назначают большую награду. И тогда за ним начинают охотиться авантюристы со всего Нового света, они преследуют его как на суше, так и на море.",
"Жизнь пиратов довольно опасна, поэтому они нередко прятали награбленные сокровища в укромных местах, тщательно составляя карту клада. Теперь такие карты довольно распространены в архипелаге и их можно купить у разных темных личностей.",
"Для умелого управления кораблем нужен опытный экипаж. Хорошая команда - большая редкость, поэтому необходимо беречь своих людей в жарких морских сражениях. Опытный врач может свести потери людей к минимуму, да и лекарства на борту корабля лишними не будут. ",
"На средних и больших кораблях помимо каюты есть ещё кают компания - отличное место, чтобы раздать необходимые указания всем своим офицерам.",
"Буканьеры всегда славились как искусные охотники и меткие стрелки. Секрет их успеха в том, что они всегда держат свое оружие в прекрасном состоянии. Так что не забывай покупать пули для пистолета и носи при себе пистолет получше. ",
"Помните, что каждый ваш поступок влияет на вашу репутацию. Мир слухами полнится, о вас также могут рассказывать много интересного. Низкая репутация может сильно повредить вам в торговых сделках, но поможет вам при устрашении противника во время абордажа. Он может даже сдаться вам без боя. ",
"Внимательно следите за моралью команды. Если она мятежная, это значит, что ваши матросы на грани бунта. Такую команду можно ублажить деньгами, ну, или ромом. Как говорится - лучше плохой маневр, чем мятеж на корабле.",
"Говорят, что в море ходит необычный для здешних мест корабль - шебека 'Синяя Птица'. Очень быстроходный парусник, а в бейдевинд ходит также, как и по ветру!",
"Знаменитой шебекой 'Синяя Птица' владеет неизвестный пират. Никто не знает, как его зовут...",
"Если встретил в море шебеку 'Синяя Птица', то считай трюм уже пуст. Уходить бесполезно, догонит всё равно...",
"Щебека 'Синяя Птица' - настоящая гроза негоциантов. Не приведи Господь встретиться с ней в море...",
"Ловцы жемчуга есть не только на западном побережье Америки. Они есть и в здешних водах, только очень уж скрытны...",
"Говорят, что Барталомью Шарп - большой любитель пограбить жемчужные промыслы.",
"Обратитесь к торговцу в магазине! Говорят, что они ищут отважного капитана, хотят нанять за неплохое вознаграждение...",
"Ходят слухи, что шебека 'Синяя Птица' здорово достала карибских торговцев. И теперь торговцы ищут капитана, который сможет избавить их от этих проблем...",
"Вы знаете, странная история произошла года три назад с одним пиратским капитаном. Этот кэп, Чард Каппер, вышел в море и пропал. Что с ним могло случиться?..",
"Говорят, что где на материке есть город ацтеков Теночтитлан. Ацтеков перебили испанцы, так что город сейчас в запустении.",
"Вы знаете, хотят слухи, что во времена покорения Америки испанцы уничтожили индейскую цивилизацию ацтеков. Их город, Теночтитлан, сейчас в запустении.",
};
/// Если новостей нет .
string NO_RUMOUR_TEXT[SIMPLE_RUMOUR_NUM] = {
"Последнее время ничего интересного не говорят. Жизнь течёт спокойно и мирно. Просто диву даёшься!",
"У нас тут тишь да гладь. А корабли заходят нечасто, поэтому никаких сколько-нибудь важных событий за последнее время не было.",
"Приход вашего судна  - вот о чём все говорят последнее время!",
"Что-то я не припомню ничего значительного. Даже драки в таверне у нас редкость.",
"Вряд ли смогу рассказать вам какие-нибудь новости, давно уже ни о чём интересном не слышно...",
"Эх, времена нынче пошли... Губернатор-то наш опять налоги поднял... вот и сосед мой с парой дружков в джунгли подались, когда их за недоимки грозились в казематы засадить... \nА что людям остается делать? Только на вольный промысел, или к капитанам лихим наниматься - всё не тюремную баланду хлебать.",
"Говорят, солдатам в гарнизоне уже чуть не год жалование из Европы не присылают. Вот ходят слухи, что на днях оттудова, из форта, значит, несколько человек дезертировало. А куда они подадутся? Известное дело - на большую дорогу... что нам не дают, то, значит, сами и возьмём. А честному человеку уже и за ворота городские выйти боязно.",
"Губернатор наш, говорят, опять себе мебеля из Старого Света заказал, в усадьбу значит. А половина солдат в форте чуть не в обносках ходят, да горошины в похлёбке на штуки считают... \nВот слыхал я, один гарнизонный офицер, продал семейные побрякушки, купил люггер и на днях ушёл в море. Его, конечно, объявили дезертиром! А что ему оставалось делать, если чины только о своём благе и пекутся?",
"Ходят слухи, что в Европе новая война зреет. Значит, опять налоги да пошлины вырастут, доброй торговле в убыток. А люд простой на большак промышлять потянется, от сборщиков да чинуш подальше... \nА кто в море подастся, у Госпожи Фортуны милости искать, да от одноногой бегать... Война с нищетой да разбоем всегда об руку ходит.",
"Слыхали, из Европы новая эскадра пришла, для усиления патрулей и борьбы с каперством, значит. Да только те патрули от пиратов токмо флагом на гроте и отличаются. \nТого и гляди - в открытом море повстречают да груз и конфискуют, а уж причину надумают. Поди потом доказывай, что не твой телок овёс топтал... Вот и приходится торговцам платить конвоирам да наёмничкам за охрану своего промысла. А нам с того что? Правильно - опять цены на ром подскочут!.. провались оно всё пропадом!",
"Поговаривают, что в Европе снова неспокойно... Значит, опять сюда беженцы да проходимцы всех мастей потянутся. А здесь кому они нужны? Верно, тут таким одна дорога - на большак промышлять, или в море разбойничать... \nЭ-хе-хе, а губернаторы опять поборы на содержание гарнизонов увеличат. Что разбойники в джунглях, что чиновники в дорогих кабинетах - простому люду всё одно - бандиты-кровопийцы...",
"А слыхали вы, о тех рыбацких тартанах, что иногда появляются возле Теркса?.. Так вот, я скажу, что нечего там рыбакам делать! В тех водах отродясь рыбы не было! \nКлянусь своим дырявым баркасом, вовек мне рому не испить... Тут явно что-то не чисто!",
"Городок-то у нас тихий. Но вот недавно была форменная баталия неподалеку тут, у маяка. Один капитан, значит, с местными дельцами контрабандой промышлял, а патруль их за этим делом и застукал! \nДурные деньги счастья не приносят, попомните мои слова! Зажали, значит, патрульные бриги шхуну того кэпа у берега, и на абордаж взяли! Самого капитана-то ядром насмерть зашибло, а местных скупщиков в форте повесили. А вот матросиков жалко - всех на факторию продали. Эх-эх... спаси, Господи, их грешные души...",
};
/// Слухи нищих
string POOR_RUMOUR_TEXT[10] = {
"Говорят, что где-то в Карибском море есть необычный остров. Кто туда приходит, тот там и остается навсегда...",
"Эх, нет правды на Карибах. Но слышал я, что есть один остров, где последние становятся первыми. И остров тот не на земле стоит...",
"Справедливость - вот мечта всех угнетенных и обиженных. И говорят, есть в Карибском море остров, где справедливость ЕСТЬ!!",
"Остров, остров Справедливости! И это не выдумки, скажу я вам, это реальность. Остров существует!",
"Попасть на остров Справедливости хоть и сложно, но можно. А вот выбраться - это вряд ли... А по мне, только бы попасть в этот рай на Карибах...",
"М-да, в этом городе я - никто. Но придёт время, и мне улыбнется удача. Нужно только добраться до ОСТРОВА...",
"Человеку свойственно стремиться к лучшему. Вот и я хочу попасть на остров, где царит справедливость. И знайте, я обязательно найду туда дорогу!",
"Пьянство сгубило меня, надо признать это честно. Теперь мне одна дорога - на остров Справедливости, и только туда...",
"Не стоит думать, что рассказы об ОСТРОВЕ - выдумка. Это правда. Вот только дороги туда не знает никто...",
"Только бы узнать, как добраться до ОСТРОВА. В тот же день отправлюсь туда!",
};
/// Если новостей нет в ГПК.
string NO_RUMOUR_LSC_TEXT[5] = {
"Скучно у нас в Городе. О каких новостях вы говорите?..",
"Какие сплетни? До следующего шторма у нас всё будет спокойно, как на кладбище.",
"Интересного ничего нет, да и не будет, наверное...",
"Ничего нового мне неизвестно. Это же Город Потерянных Кораблей!",
"Никаких новостей, никаких сплетен. До очередного шторма, конечно.",
};

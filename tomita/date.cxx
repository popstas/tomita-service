#encoding "utf8"

NotAction -> 'не' Verb;

Stage -> Word<kwtype="этап глагол">;

PrepNoun -> Prep Noun<kwtype="этап существительное">;
Object -> Word<kwtype="объект">;
Object -> Word<kwtype="страховой",gnc-agr[1]> Word<kwtype="кто страховой", gnc-agr[1], rt>;
ProductName -> Word<kwtype="название_продукта">;
ProductName -> Word<kwtype="каско"> | Word<kwtype="осаго">;

RealLive -> Word<kwtype="события реальной жизни">;

//FullObjectName -> Object* ProductName;

//S -> NotAction Stage interp (FactType.FailAction::not_norm) Object* interp (FactType.TargetObject) ProductName interp (FactType.TargetProduct);
S -> (NotAction) Stage interp (FactType.FailAction::not_norm) (Adj*) Object* interp (FactType.TargetObject) (Adj*) ProductName interp (FactType.TargetProduct);
S -> ProductName interp (FactType.TargetProduct);
S -> (Prep) Noun<kwtype="этап существительное"> interp (FactType.FailAction) Object* interp (FactType.TargetObject) ProductName interp (FactType.TargetProduct);
S -> PrepNoun interp (FactType.FailAction);
S -> RealLive interp (FactType.LiveAction);
S -> Object interp (FactType.TargetObject);
S -> Word<gram="obsc"> interp (FactType.BadWord);
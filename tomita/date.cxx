#encoding "utf8"

NotAction -> 'не' Verb;
Stage -> Word<kwtype="этап глагол">;

//PrepNoun -> Prep Noun<kwtype="этап существительное">;

Object -> Word<kwtype="объект">;
ProductName -> Word<kwtype="название_продукта">;

//FullObjectName -> Object* ProductName;

//S -> NotAction Stage interp (FactType.FailAction::not_norm) Object* interp (FactType.TargetObject) ProductName interp (FactType.TargetProduct);
S -> NotAction Stage interp (FactType.FailAction::not_norm) Object* interp (FactType.TargetObject) ProductName interp (FactType.TargetProduct);
S -> Prep Noun<kwtype="этап существительное"> interp (FactType.FailAction) Object* interp (FactType.TargetObject) ProductName interp (FactType.TargetProduct);

